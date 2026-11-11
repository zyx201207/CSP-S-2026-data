#include<bits/stdc++.h>
using namespace std;

struct st{
	int a;
	char c;
};

st s[200005];

int n;
long long ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int i=1,j=n;
	while(i<j){
		if(s[i].c==s[j].c){
			if(s[i].a>s[j].a){
				s[i].a-=s[j].a;
				s[j].a=0;
				j--;
			}else if(s[j].a>s[i].a){
				s[j].a-=s[i].a;
				s[i].a=0;
				i++;
			}else{
				i++;
				j--;
			}
		}else{
			ans+=min(s[i].a,s[j].a);
			if(s[i].a<s[j].a){
				s[j].a-=s[i].a;
				s[i].a=0;
				if(s[i-1].a>0 || s[j+1].a>0){
					s[j].a-=(s[i-1].a+s[j+1].a);
					s[i-1].a=0;
					s[j+1].a=0;
				}
				i++;
			}else if(s[j].a<s[i].a){
				s[i].a-=s[j].a;
				s[j].a=0;
				if(s[i-1].a>0 || s[j+1].a>0){
					s[i].a-=(s[i-1].a+s[j+1].a);
					s[i-1].a=0;
					s[j+1].a=0;
				}
				j--;
			}else{
				s[i].a=0;
				s[j].a=0;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
