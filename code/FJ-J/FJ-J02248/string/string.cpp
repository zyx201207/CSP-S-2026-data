#include<bits/stdc++.h>
using namespace std;
struct S{
	char c;
	int a;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	S s[n];
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int l=0,r=n-1;l<=r;){
		if(s[l].c!=s[r].c){
			sum+=min(s[l].a,s[r].a);
		}
		if(s[l].a>s[r].a){
			s[l].a-=s[r].a;
			s[r].a=0;
			r--;
		}else if(s[r].a>s[l].a){
			s[r].a-=s[l].a;
			s[l].a=0;
			l++;
		}else{
			s[l].a-=s[r].a;
			s[r].a=0;
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}
