#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a[200011],ans;
bool b[200011];

bool calc(int x){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			if(a[i]&(1<<x)){
				cnt++;
			}
		}
	}
	if(cnt>=m){
		for(int i=1;i<=n;i++){
			if(!b[i]){
				if(!(a[i]&(1<<x))){
					b[i]=1;
				}
			}
		}
		return 1;
	}else{
		return 0;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=29;i>=0;i--){
		if(calc(i)){
			ans+=(1<<i);
		}
	}
	cout << ans;
	return 0;
}

