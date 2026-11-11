#include<bits/stdc++.h>
using namespace std;
struct len{
	long long l;
	char c;
}str[5000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].l>>str[i].c;
	}
	long long ll=1,rr=n,ans=0;
	while(true){
		if(str[ll].l>str[rr].l){
			if(str[ll].c!=str[rr].c){
				ans+=str[rr].l;
			}
			str[ll].l-=str[rr].l;
			rr--;
		}else if(str[ll].l<str[rr].l){
			if(str[ll].c!=str[rr].c){
				ans+=str[ll].l;
			}
			str[rr].l-=str[ll].l;
			ll++;
		}else{
			if(str[ll].c!=str[rr].c){
				ans+=str[ll].l;
			}
			ll++;
			rr--;
		}
		if(ll>=rr)break;
	}
	cout<<ans;
	return 0;
}
