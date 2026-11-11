//贵阳市白云区华师一学校 刘骏轩 GZ-J00038
#include<bits/stdc++.h>
using namespace std;
int arr[500005];
vector<int>vec[500005];
int a[500005];
int bu[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(arr,0,sizeof(arr));
		int sz=1;
		for(int j=i;j<=n;j++){
			for(int k=1;k<sz;k++){
				if(a[j]==arr[k]){
					for(int l=k;l<sz;l++){
						arr[l]=0;
					}
					sz-=sz-k;
				}
			}
			arr[sz]=a[j];
			sz++;
		}
		for(int j=1;j<sz;j++){
			vec[i].push_back(arr[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j:vec[i]){
			bu[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<bu[i]<<" ";
	}
	return 0;
}
