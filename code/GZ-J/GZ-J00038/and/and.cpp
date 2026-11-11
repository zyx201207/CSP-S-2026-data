//贵阳市白云区华师一学校 刘骏轩 GZ-J00038
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		int mx=INT_MIN;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int num=a[1];
		for(int i=2;i<=n;i++){
			num&=a[i];
		}
		cout<<num;
		return 0;
	}
	if(m==n-1){
        int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			int num=INT_MAX;
			for(int j=1;j<=n;j++){
				if(j!=i){
					num&=a[j];
				}
			}
            mx=max(mx,num);
		}
		cout<<mx;
		return 0;
	}
	sort(a+1,a+n+1);
	int num=INT_MAX;
	for(int i=n;i>n-m;i--){
		num&=a[i];
	}
	cout<<num;
	return 0;
}
