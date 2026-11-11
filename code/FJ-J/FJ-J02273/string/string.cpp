#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

//string a[100010];

struct hwc{
	int a;
	char b;
}sum[200010];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum[i].a>>sum[i].b;
	}
	int a=1;
	int ant=0;
	for(int i=1;i<=n;){
		if(i==n-i+a){
			cout<<ant;
			return 0;
		}else if(sum[i].b==sum[n-i+a].b){
			if(sum[i].a>sum[n-i+a].a){
				sum[i].a-=sum[n-i+a].a;
				a--;
			}else if(sum[i].a<sum[n-i+a].a){
				sum[n-i+a].a-=sum[i].a;
				i++;
				a++;
			}else if(sum[i].a==sum[n-i+a].a){
				sum[n-i+a].a=0;
				sum[i].a=0;
				i++;
			}
		}else if(sum[i].b!=sum[n-i+a].b){
			ant+=min(sum[i].a,sum[n-i+a].a);
			if(sum[i].a>sum[n-i+a].a){
				sum[i].a-=sum[n-i+a].a;
				a--;
			}else if(sum[i].a<sum[n-i+a].a){
				sum[n-i+a].a-=sum[i].a;
				i++;
				a++;
			}else if(sum[i].a==sum[n-i+a].a){
				sum[n-i+a].a=0;
				sum[i].a=0;
				i++;
			}
		}
	}
	cout<<ant;
	return 0;
} 
