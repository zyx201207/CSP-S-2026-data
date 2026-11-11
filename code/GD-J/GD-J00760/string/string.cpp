#include<bits/stdc++.h> 
using namespace std;
int n;
long long ans=0;
struct o{
	int a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	o s[n+5];
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int i=1,j=n;i<=j;){
		if(s[i].c==s[j].c){
			if(s[i].a<s[j].a){
				int t=s[j].a-s[i].a;
				s[j].a=t;
				i++; 
			}
			else if(s[i].a==s[j].a){
				i++;
				j--;
			}
			else{
				int t=s[i].a-s[j].a;
				s[i].a=t;
				j--; 
			}
		}
		else{
			if(s[i].a<s[j].a){
				int t=s[j].a-s[i].a;
				ans+=s[i].a;
				s[j].a=t;
				i++; 
			}
			else if(s[i].a==s[j].a){
				ans+=s[i].a;
				i++;
				j--;
			}
			else{
				int t=s[i].a-s[j].a;
				ans+=s[j].a;
				s[i].a=t;
				j--; 
			}
		}
	}
	cout<<ans;
	return 0;
}



