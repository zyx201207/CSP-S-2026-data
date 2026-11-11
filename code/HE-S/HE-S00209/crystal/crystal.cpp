#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
bool flag=true;
long long m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if((a[i]-a[i-1])!=(a[i-1]-a[i-2])) flag=false;
	}
	if(flag){
		long long cha=a[2]-a[1];
		cout<<(m/cha)+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int l=i-1,r=i+1;
		long long sum=0,cnt=1;
		bool l_f=true,r_f=true;
		
		while(sum<=m){
			if(l<1) l_f=false;
			if(r>n) r_f=false;
			if(l_f && r_f){
				long long l_num=0,r_num=0;
				l_num=abs(a[l--]-a[i]);
				r_num=abs(a[r++]-a[i]);
			//	cout<<l_num<<" l_num "<<r_num<<" r_num"<<'\n';
				long long minn=min(l_num,r_num);
			//	cout<<"sum+minn "<<sum+minn<<'\n';
				if(sum+minn<=m){
					sum+=minn;
					cnt++;
	//				cout<<cnt<<" cnt "<<minn<<" minn"<<'\n';
				}
				else break;
			}else if(l_f){
				long long l_num=0;
				l_num=abs(a[l--]-a[i]);
				if(sum+l_num<=m){
					sum+=l_num;
					cnt++;
	//				cout<<cnt<<" cnt "<<minn<<" minn"<<'\n';
				}
				else break;
			}else if(r_f){
				long long r_num=0;
				r_num=abs(a[r++]-a[i]);
				if(sum+r_num<=m){
					sum+=r_num;
					cnt++;
	//				cout<<cnt<<" cnt "<<minn<<" minn"<<'\n';
				}
				else break;
			}else break;
		}
	//	cout<<i<<" ans "<<ans<<" cnt "<<cnt<<'\n';
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
