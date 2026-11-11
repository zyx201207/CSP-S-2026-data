#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1;
int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a==c){
		ans1=1;
		if(int(b[0])+int(b[1])==int(d[0])+int(d[1])){
			ans2=1;
			if((int(b[2])<=67 && int(d[2])<=67) || (int(b[2])>67 && int(d[2])>67)){
				ans3=1;
				if(abs(int(b[2])-int(d[2]))==1){
					ans4=1;
				}
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
