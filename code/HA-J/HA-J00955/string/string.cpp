#include<bits/stdc++.h>
using namespace std;
int n;
long long h;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int s1=1,s2=n;
	for(int i=0;i<=n;i--){
		if(s1==s2||s1>s2){
			break;
		}
		if(c[s1]==c[s2]){
			if(a[s1]>a[s2]){
				a[s1]-=a[s2];
				s2--;
			}else if(a[s1]<a[s2]){
				a[s2]-=a[s1];
				s1++;
			}else if(a[s1]==a[s2]){
				s1++;
				s2--;
			}
		}
		if(c[s1]!=c[s2]){
			if(a[s1]>a[s2]){
				h+=a[s2];
				a[s1]-=a[s2];
				s2--;
			}else if(a[s1]<a[s2]){
				h+=a[s1];
				a[s2]-=a[s1];
				s1++;
			}else if(a[s1]==a[s2]){
				h+=a[s1];
				s1++;
				s2--;
			}
		}
	}
	cout<<h;
	return 0;
}