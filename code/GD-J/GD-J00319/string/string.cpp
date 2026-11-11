#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int i=0,j=n-1;
	while(i<j){
		if(s[i].c==s[j].c){
			if(s[i].a>s[j].a){
				s[i].a=s[i].a-s[j].a;
				j--;
			}else if(s[i].a==s[j].a){
				i++;
				j--;
			}else{
				s[j].a=s[j].a-s[i].a;
				i++;
			}
		}else{
			if(s[i].a>s[j].a){
				ans+=s[j].a;
				s[i].a=s[i].a-s[j].a;
				j--;
			}else if(s[i].a==s[j].a){
				ans+=s[i].a;
				i++;
				j--;
			}else{
				ans+=s[i].a;
				s[j].a=s[j].a-s[i].a;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 

