#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  n,m,a[200020];//ccf保佑我不报零！！！！！！！！！！！ 
ll cnt=0,cntf=0;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n,cmp);
	for(int i=0;i<5;i++) cout<<a[i]<<' ';
	cnt=a[0];ll i=0;
	while(1){
		i++;
		if(a[i]!=cnt){
			cntf=a[i];
			break;
		}
	}
	for(ll q=1;q<m;q++){
		cnt=(cnt & a[q]);
	}for(int q=i;q<i+m;q++){
		cntf=(cntf & a[q]);
	}
	cout<<max(cnt,cntf)<<endl;
	return 0;
} 
