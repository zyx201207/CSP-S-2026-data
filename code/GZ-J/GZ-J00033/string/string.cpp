// GZ-J00033 ºÎçâå· 
#include<bits/stdc++.h>
using namespace std;
int a[100005];
char s[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<r;){
		int ai;
		cin>>ai;
		char c;
		cin>>c;
		if(c!=s[i]&&s[i]!='\0'){
			i++;
		}
		else if(c==s[i]&&s[i]!='\0'){
			r--;
		}
		a[i]+=ai;
		s[i]=c;
	}
	cout<<r;
	int sum=0;
	while(r>l){
		if(a[l]<a[r]){
			a[r]-=a[l];
			if(s[l]!=s[r]){
				sum+=a[l];
			}
			l++;
		}
		else if(a[r]<a[l]){
			a[l]-=a[r];
			if(s[l]!=s[r]){
				sum+=a[r];
			}
			r--;
		}
		else{
			if(s[l]!=s[r]){
				sum+=a[l];
			}
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}
