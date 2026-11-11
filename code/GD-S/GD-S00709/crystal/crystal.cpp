#include<bits/stdc++.h>
using namespace std;
#define endl '\n'//Phua is forbiden . But Phua everywhere !
const int maxn=5e5+5;
int n,m;
int a[maxn];
bool check(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[i];
	}
//	cout<<"sum:"<<sum<<endl;
	if((sum+m)%x==0){
		for(int i=1;i<=x;i++){
//			cout<<(sum+m)/x<<" "<<a[i]<<endl; 
			if(((sum+m)/x)<a[i]){
//				cout<<"akioi\n";
				return false;
			} 
		}
	}else return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		if(check(i)==0){
			cout<<i-1<<endl;
			break;
		}
	}
	return 0;
}

