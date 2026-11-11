// 贵阳普瑞 刘浩淇 GZ-S00176
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int fin(int num,int goa,int add,int cnt){
    int les = a[goa] - a[num];
    if(a[goa] < a[num] || add < les || num > n){
        return cnt;
    }
    if(a[num] == a[goa]){
        fin(num + 1,goa,add,cnt + 1);
    }else if(add >= les){
        fin(num + 1,goa,add - les,cnt + 1);
    }
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i = 1;i <= n;i++){
        cin>>a[i];
	}
	int cnt = 0;
	for(int i = 1;i < n;i++){
        for(int j = a[i];j <= a[n];j++){
            cnt = max(cnt,fin(i,j,m,0));
        }
    }
	cout<<cnt;
	return 0;
}
