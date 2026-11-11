#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,a,maxn = 0 ;
	vector<ll>Sum(n+1,0);
	cin>>n>>m;
	vector<ll>A(n);
	A[0] = -1e18;
	for(ll i = 1;i<=n;i++){
		cin>>a;
		A[i] = a;
	}
	//cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3];
	ll C[n+2];
	C[0] = -1e18;
	C[n+1] = 1e18;
	sort(A.begin(),A.end()+1);
	//cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3]<<endl;
	for(ll i = 1;i<=n;i++){
        ll p =A[i];
		Sum[i]=Sum[i-1]+p;
	}
	//cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3]<<endl;
	for(ll i = 1;i<=n;i++){
		C[i] = A[i]*i-Sum[i];//dai jia
	}
	//cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3]<<endl;
	ll l= n/2;
	bool aaaa = 0;
	//cout<<C[3]<<" "<<A[3]<<" "<<Sum[3]<<" "<<m<<endl;
	//cout<<C[3]<<endl;
	//cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3];
	ll k = 0,ans = 0;
	while(n-k-1){
            k++;
        if(C[k]==C[k+1]){
            ans++;
        }

	}
	ans++;
	for(ll i = 1;i<=n;i++){
		//cout<<l<<" ";
		if(aaaa == 0){
            if(C[n]<=m){
                l = n;
                break;
            }
            if(C[1]>=m){
                l = max((ll)1,ans);
                break;
            }
		}
		aaaa = 1;
		if(C[l]==m){
            if(C[l] == C[l+1]&&C[l] == C[l-1]){
                while(C[l] == C[l-1]){
                    l--;
                }
                while(C[l] == C[l+1]){
                    l++;
                }
            }
            else if(C[l] == C[l+1]){
                while(C[l] == C[l+1]){
                    l++;
                }
            }
            else if(C[l] == C[l-1]){
                while(C[l] == C[l-1]){
                    l--;
                }
            }
            break;
		}
		else if(C[l]<m&&C[l+1]>m){
			break;
		}
		else if(C[l]>m&&C[l-1]<m){
			l-=1;
			break;
		}
		else if(C[l]>m){
			l=l/2;
		}
		else if(C[l]<m){
			if(l!=1){
				l = l+(l/2);
			}
			else{
				l = l+(l/2)+1;
			}
		}
		//cout<<l<<" ";
	}
	cout<<l;//3h 49 min dp->erfen+tanxin geidianfenba
	return 0;
}

