#include<bits/stdc++.h>
using namespace std;
struct str{
	long long ans;
	char tmp;
};
str s[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>s[i].ans;
		cin>>s[i].tmp;
	}
	
	int j=n,k=1;
	long long diff=0;
	for(int i=1;i<=n;i++){	
		if(s[k].ans<=s[j].ans){
			if(s[k].tmp!=s[j].tmp){
				diff+=s[k].ans;
		    }
		    s[j].ans-=s[k].ans;
		    s[k].ans=0;
		    k++;
		    if(s[j].ans==0){
		    	j--;
			}
		}
		else if(s[k].ans>s[j].ans){
			if(s[k].tmp!=s[j].tmp){
				diff+=s[j].ans;
			}
			s[k].ans-=s[j].ans;
		    s[j].ans=0;
		    j--;
		    if(s[k].ans==0){
		    	k++;
			}
		}
	}

	cout<<diff;
	
	
	return 0;
}
