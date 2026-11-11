#include<bits/stdc++.h>
using namespace std;
//1 3
//能拿3个点就是胜利
//模拟万岁
long long n,m;
long long a[500010];
vector<int> v;
long long t[300010];
long long ans[300010];
//long long t1[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
//	cout<<"input=v\n";
	for(int i=1;i<=n;i++){
	//	cout<<"range"<<i<<endl;
		memset(t,0,sizeof(t));
		while(!v.empty()) v.pop_back();
		for(int j=i;j<=n;j++){
			if(t[a[j]]>0){
			//	cout<<a[j]<<"existed"<<endl;
				while(v[v.size()-1]!=a[j]){
					t[v[v.size()-1]]--;
					v.pop_back();
				}
				v.pop_back();
				t[a[j]]--;
			}
//			cout<<"OK in card"<<j<<endl;
			v.push_back(a[j]);
			t[a[j]]++;
//			for(auto it=v.begin();it!=v.end();it++){
//				cout<<*it<<" ";
//			}
//			cout<<"\n";
//			for(int l=1;l<=m;l++){
//				cout<<t[i]<<" ";
//				
//			}
//			cout<<"\n";
		}
		for(int i=1;i<=m;i++){
			if(t[i]!=0) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
