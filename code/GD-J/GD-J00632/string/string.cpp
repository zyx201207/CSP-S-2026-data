#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x,ans=0;
char y;
struct o{
	ll num;
	char zm;
}s[10000000];
bool cmp(o a,o b){
	return a.num>b.num;
}
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		s[i].num=x;
		s[i].zm=y;
	}
	for(int i=0,j=n-1;i<j;){
		if(s[i].zm!=s[j].zm){
			bool flag=1;
			while(flag){
				if(i==j){
					break;
				}
				if(s[i].zm==s[j].zm){
					if(s[i].num>s[j].num){
						ans+=s[i].num-s[j].num;
						s[i].num-=s[j].num;
					}
					j--;
					break;
				}
				if(i==j){
					break;
				}
				if(s[i].num>s[j].num){
					ans+=s[j].num;
					s[i].num-=s[j].num;
					j--;
				}else{
					s[j].num-=s[i].num;
					ans+=s[i].num;
					i++;
				}
			}
		}else{
			if(s[i].num>s[j].num){
				ans+=s[i].num-s[j].num;
				s[i].num-=s[j].num;
			}
			j--;
		}
	}
	cout<<ans;
	//»Ö¸´freopen 
	
	return 0;
}
//aaabbdddbbe
//aaabbdbbaaa
 
