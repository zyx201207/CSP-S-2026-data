#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 5e5;
int arr[N];
int n, m;
bool check(int x){
    int maxv = arr[x-1];
    int en = m;
    for(int i = 0; i < x; i++){
	en -= maxv-arr[i];
    }
    return en >= 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l = 0, r = n, ans = 0;
    while(l<=r){
	int mid = (l+r)/2;
	if(check(mid)){
	    ans = mid;
	    l = mid +1;
	}else{
	    r = mid -1;
	}
    }
    cout<<ans<<endl;
}
