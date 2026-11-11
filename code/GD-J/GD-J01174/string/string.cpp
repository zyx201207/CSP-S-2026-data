#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n;
int a[N];
char c[N];
string s="";
long long cnt=0;
long long l=0;
int t=1;
int main(){
	freopen("string.in",r);
	freopen("string.out",w);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
		l+=a[i];
	}
	for(int i=1,j=n;i<j;i++){
		
		if(c[i]!=c[j]){
			if(a[i]>=a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				j--;
				i--;
			}
			else{
				cnt+=a[i];
				a[j]-=a[i];
			} 
		}
		if(c[i]==c[j]){
			j--;
		}
	}
	cout<<cnt;
	return 0;
}
