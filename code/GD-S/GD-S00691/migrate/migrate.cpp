#include<bits/stdc++.h>
using namespace std;

long long arr[10];
long long ans=0;
pair<long long,long long> cnt[10];
long long n,d;

void dfs(long long num,long long t){
	if (cnt[num].first>t){
		cnt[num].first=t;
		cnt[num].second=1;
	}
	else if (cnt[num].first==t){
		cnt[num].second++;
	}
	else{
		return ;
	}
//	cout<<num<<" "<<t<<endl;
	for (long long i=num+1;i<=n;i++){
		if (arr[i]-arr[num]>d){
			break; 
		}
		dfs(i,t+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while (t--){
		ans=0;
		cin>>n>>d;
		for (long long i=1;i<=n;i++){
			cin>>arr[i];
		}
		for (long long i=1;i<=n;i++){
			for (long long j=1;j<=n;j++){
				cnt[j].first=0x3f3f3f3f;
				cnt[j].second=0;
			}
//			cout<<i<<":";
			dfs(i,0);
			for (long long j=1;j<=n;j++){
//				cout<<cnt[j].first<<" "<<cnt[j].second<<endl;
				if (cnt[j].second==2){
					ans++;
				}
			}
//			cout<<endl;
		}
		cout<<ans<<endl; 
	}
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	long long c,t;
//	cin>>c>>t;
//	while (t--){
//		bool ok=false;
//		long long n,d;
//		cin>>n>>d;
//		long long l,r;
//		long long ans=0;
//		long long num1=-0x3f3f3f3f3f3f3f3f,num2=-0x3f3f3f3f3f3f3f3f,num3=-0x3f3f3f3f3f3f3f3f,num4=-0x3f3f3f3f3f3f3f3f;
//		for (long long i=1;i<=n;i++){
//			num1=num2;
//			num2=num3;
//			num3=num4;
//			cin>>num4;
//			if (num4-num3>d){
//				l=0;
//				r=1;
////				cout<<"init"<<endl;
//				continue;
//			}
//			r++;
//			if (i>=4 and num4-num1>d and num4-num2<=d and num3-num1<=d){
//				r-=3;
//				l=r;
//				r=3;
//				ok=true;
////				cout<<"?";
//			}
//			if (ok){
//				ans+=l;
//			}
//			cout<<i<<" "<<ans<<":"<<l<<" "<<r<<":"<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<endl;
//		}
//		cout<<ans<<endl;
//	}
//	return 0;
//}
