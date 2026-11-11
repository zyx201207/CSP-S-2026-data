#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
int n;
struct hw{
	ll a;
	char c;
}str[N];
ll sum,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].c;
		sum+=str[i].a;
	} 
	if(sum%2==1){
		for(int i=1;i<=n;i++){
			x+=str[i].a;
			if(x>=(sum+1)/2){
				str[i].a--;
				break;
			} 
		}
	}
	x=0;
	int l=1,r=n;
	while(l<=r){
		if(str[l].c != str[r].c){
			if(str[l].a == str[r].a){
				x+=str[l].a;
				l++,r--;
			}else if(str[l].a > str[r].a){
				x+=str[r].a;
				str[l].a-=str[r].a;
				r--;
			}else if(str[l].a < str[r].a){
				x+=str[l].a;
				str[r].a-=str[l].a;
				l++;
			}
		}else{
			if(str[l].a == str[r].a){
				l++,r--;
			}else if(str[l].a > str[r].a){
				str[l].a-=str[r].a;
				r--;
			}else if(str[l].a < str[r].a){
				str[r].a-=str[l].a;
				l++;
			}
		}
	}cout<<x;
	return 0;
}


