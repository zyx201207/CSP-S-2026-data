#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
long long ans;
struct charr{
	int num;
	char c;
}ch[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int temp;
		char t;
		cin>>temp>>t;
		ch[++cnt].num=temp;
		ch[cnt].c=t;
	}
	int l=1,r=n;
	while(l<r){
		if(ch[l].c!=ch[r].c){
			if(ch[l].num<=ch[r].num){
				ans+=ch[l].num;
				ch[r].num-=ch[l].num,ch[l].num=0;
				l++;
			}		
			else{
				ans+=ch[r].num;
				ch[l].num-=ch[r].num,ch[r].num=0;
				r--;
			}		
		}else{
			if(ch[l].num<=ch[r].num){
				ch[r].num-=ch[l].num,ch[l].num=0;
				l++;
			}		
			else{
				ch[l].num-=ch[r].num,ch[r].num=0;
				r--;
			}	
		}
	}
	cout<<ans;
	return 0;
}
