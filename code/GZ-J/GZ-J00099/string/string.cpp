//GZ-J00099 ¶Å³¿¼Î 
#include<bits/stdc++.h>
using namespace std;
int n;
//long long l=0;
long long mx=0;
long long a[200001];
char c[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	//	l+=a[i];
	}
	int i=1,j=n;
	while(i<=j){
		if(a[i]==a[j]){
			if(c[i]!=c[j]){
				mx+=a[i];
			}
			i++;
			j--;
		}else if(a[i]>a[j]){
			if(c[i]!=c[j]){
				mx+=a[j];
			}
			a[i]=a[i]-a[j];
			a[j]=0;
			j--;
		}else{
			if(c[i]!=c[j]){
				mx+=a[i];
			}
			a[j]=a[j]-a[i];
			a[i]=0;
			i++;
		}
	}
	cout<<mx;
	return 0;
}
