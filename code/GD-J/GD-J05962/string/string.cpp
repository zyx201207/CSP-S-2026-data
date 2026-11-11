#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
struct qwe{
	long long num;
	long long sum;
	char c;
}a[N];
int n=0;
long long mid=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
		
	int n1;
	cin>>n1;
	a[0].c='#';
	a[0].num=0;
	int nv;
	char cv;
	for(int i=1;i<=n1;++i){
		cin>>nv>>cv;
//		mid+=nv;
		if(cv==a[n].c){
			a[n].num+=nv;
			a[n].sum+=nv;
		}
		else{
			n++;
			a[n].c=cv;
			a[n].sum=nv;
			a[n].num=a[n-1].num+nv;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
//	cout<<a[1].c<<"//a[1].c\n";
//	for(int i=1;i<=n;++i){
//		cout<<a[i].c<<" "<<a[i].sum<<" "<<a[i].num<<"\n";
//	}
	
	
	mid=a[n].num/2;
	if(a[n].num%2!=0)mid++;
	int id_mid=n/2;
	long long now=0,end_now=a[n].sum;
	int n_is=1,n_ie=n;
//	cout<<ans<<"___________s\n";
//				cout<<n_is<<" "<<a[n_is].c<<" "<<a[n_is].sum<<" "<<a[n_is].num<<"\n";
//				cout<<n_ie<<" "<<a[n_ie].c<<" "<<a[n_ie].sum<<" "<<a[n_ie].num<<"\n";
//				cout<<now<<" "<<end_now<<"------------s\n";
	while(1){
		
		if(a[n_is].num>mid){
//			cout<<"//1\n";
			long long chao=a[n_is].num-mid;
			long long shen=a[n_is].sum-chao-chao;
				while(shen>=end_now){
					if(a[n_is].c!=a[n_ie].c){
					ans+=end_now;
//					cout<<ans<<"___________e\n";
//				cout<<n_is<<" "<<a[n_is].c<<" "<<a[n_is].sum<<" "<<a[n_is].num<<"\n";
//				cout<<n_ie<<" "<<a[n_ie].c<<" "<<a[n_ie].sum<<" "<<a[n_ie].num<<"\n";
//				cout<<now<<" "<<end_now<<"------------e\n";
					}
					n_ie--;
					shen-=end_now;
					end_now=a[n_ie].sum;
				}
			break;
		}
//		cout<<"//2\n";
			long long shen=a[n_is].sum;
			while(shen>=end_now){
				if(a[n_is].c!=a[n_ie].c){
				ans+=end_now;
				
//				cout<<ans<<"____________\n";
//				cout<<n_is<<" "<<a[n_is].c<<" "<<a[n_is].sum<<" "<<a[n_is].num<<"\n";
//				cout<<n_ie<<" "<<a[n_ie].c<<" "<<a[n_ie].sum<<" "<<a[n_ie].num<<"\n";
//				cout<<now<<" "<<end_now<<"-------------\n";
				}
				n_ie--;
				shen-=end_now;
				end_now=a[n_ie].sum;
			}
			if(shen<end_now){
				if(a[n_is].c!=a[n_ie].c){
				ans+=shen;}
				n_ie--;
				end_now-=shen;
			}
			now=a[n_is].num;
			n_is++;
			if(n_is>=id_mid)break;
	}
	cout<<ans;
	
	return 0;
} 
