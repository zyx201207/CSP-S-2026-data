#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	int len;
	char ch;
}str[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].len>>str[i].ch;
	}
	//for(int i=1;i<=n;i++) cout<<str[i].len<<" ";
	//cout<<'\n';
	int l=1,r=n;
	while(l<r){
		if(str[l].ch==str[r].ch){
			//cout<<"1 -> ";
			if(str[l].len<str[r].len){
				//cout<<"1";
				str[r].len -= str[l].len;
				l++;
			}
			else if(str[l].len>str[r].len){
				//cout<<"2";
				str[l].len -= str[r].len;
				r--;
			}
			else{
				//cout<<"3";
				l++;
				r--;
			}
		}
		else{
			//cout<<"2 -> ";
			if(str[l].len<str[r].len){
				//cout<<"1";
				ans += str[l].len;
				str[r].len -= str[l].len;
				l++;
			}
			else if(str[l].len>str[r].len){
				//cout<<"2";
				ans += str[r].len;
				str[l].len -= str[r].len;
				r--;
			}
			else{
				//cout<<"3";
				ans += str[l].len;
				l++;
				r--;
			}
		}
		//cout<<"  l : "<<l<<"  "<<str[l].len<<"  r : "<<r<<"  "<<str[r].len<<"  ans : "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
