#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt;
int n,c,e;
int d;
char x[200005];
int a[200005];
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
    cin>>n;
    int i=0,j=0;
    while(i<n){
		cin>>a[i]>>x[i];
	//	e+=a[i];
		i++;
	}
	i=0;
	j=n-1;
	if(n%2==0){

	}else{
	cnt--;
	}
		while(j>i){
		if(x[i]!=x[j]){
			if(a[i]>a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				a[j]=0;
				j--;
			}else if(a[i]==a[j]){
				cnt+=a[j];
				a[i]=0;
				a[j]=0;
				i++;j--;
			}else{
				cnt+=a[i];
				a[j]-=a[i];
				a[i]=0;
				i++;
			}			
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
			}else if(a[i]==a[j]){
				a[i]=0;
				a[j]=0;
				i++;j--;
			}else{
				a[j]-=a[i];
				a[i]=0;
				i++;
			}
		}
	}	
	cout<<cnt;
	return 0;
}
