#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int inf=2e5+10;
struct str{
	int num;
	char c;
};
str ic[inf];
int n;
ll ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ic[i].num>>ic[i].c;
	}
	if(n==1){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==2){
		if(ic[1].c==ic[2].c) ans=0;
		else ans=min(ic[1].num,ic[2].num);
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int l=1,r=n;
	while(l<=r){
		int o=ic[l].num,p=ic[r].num;
		if(ic[l].c==ic[r].c){
			if(o!=p){
				if(o<p) ic[r].num=ic[r].num-ic[l].num,r++;
				if(o>p) ic[l].num=ic[l].num-ic[r].num,l--;
			}
		}
		else{
			if(o==p){
				ans+=o;
			}
			else{
				if(o<p) ic[r].num=ic[r].num-ic[l].num,r++,ans+=o;
				if(o>p) ic[l].num=ic[l].num-ic[r].num,l--,ans+=p;
			}
		}
		l++,r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
