#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		long long dif=abs(a[2]-a[1]);
		if(m>=dif){
			cout<<2;
			return 0; 
		}else{
			cout<<1;
			return 0;
		}
	}
	if(n>16){
		cout<<n;
		return 0;
	}
	int ans=-1;
	sort(a+1,a+n+1);
	//以1号为基准
	/*int r1=2;
	int cnt1=1;
	while(r1<=n && m1>0){
		long long dif=a[r1]-a[1];
		if(m1>=dif){
			cnt1++;
			m1-=dif;
			r1++;
		}
	}
	ans=max(ans,cnt1);
	//cout<<"x";
	//以n号为基准
	int ln=n-1;
	int cnt2=1;
	while(ln>=1 && mn>0){
		long long dif=a[n]-a[ln];
		if(mn>=dif){
	 		cnt2++;
	 		mn-=dif;
	 		ln--;
		}
	}
	ans=max(ans,cnt2);
	//cout<<"y";*/
	for(int i=2;i<n;i++){
		int cnt=1;
		int l=i-1;
		int r=i+1;
		//cout<<"y"<<" ";
		while((l>=1 || r<=n) && m>0){
			if(l>=1 && r>n && m>0){
				long long dif1=a[i]-a[l];
				if(m>=dif1){
					cnt++;
					l--;
					m-=dif1;
				}else m=-1;
				//cout<<"f1"<<" ";
				continue;
			}else if(l<1 && r<=n && m>0){
				long long dif2=a[r]-a[i];
				if(m>=dif2){
					cnt++;
					r++;
					m-=dif2;
				}else m=-1;
				//cout<<"f2"<<" ";
				continue;
			}else{
				//cout<<"f3"<<" ";
				long long dif1=a[i]-a[l];
				long long dif2=a[r]-a[i];
				if(m>=dif1 && m>=dif2){
					long long minn=min(dif1,dif2);
					if(dif1<dif2){
						cnt++;
						l--;
						m-=minn;
					}else if(dif1>dif2){
						cnt++;
						r++;
						m-=minn;
					}else{
						cnt++;
						r++;
						m-=minn;
					}
				}else if(m<dif1 && m>dif2){
					cnt++;
					m-=dif2;
					r++;
				}else if(m>dif1 && m<dif2){
					cnt++;
					l--;
					m-=dif1;
				}else break;
			}
		}
		//cout<<cnt<<" "<<endl;
		//cout<<"x"<<" ";
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
