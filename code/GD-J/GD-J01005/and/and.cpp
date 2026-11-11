#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[200005], b[200005];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)cin>>a[i];
	if(m==1){
		int ma=INT_MIN;
		for(int i = 1; i <= n; i++)ma=max(ma, a[i]);
		cout<<ma;
		return 0;
	}
	else if(m==2){
		int ma=INT_MIN;
		for(int i = 1; i < n; i++){
			for(int j = i+1; j <= n; j++)ma=max(ma, a[i]&a[j]);
		}
		cout<<ma;
		return 0;
	}
	else if(m==3){
		int ma=INT_MIN;
		for(int i = 1; i < n-1; i++){
			for(int j = i+1; j < n; j++)
				for(int k = j+1; k <= n; k++)ma=max(ma, a[i]&a[j]&a[k]);
		}
		cout<<ma;
		return 0;
	}
	else if(m==4){
		int ma=INT_MIN;
		for(int i = 1; i < n-2; i++){
			for(int j = i+1; j < n-1; j++)
				for(int k = j+1; k < n; k++)
					for(int l = k+1; l <= n; l++)ma=max(ma, a[i]&a[j]&a[k]&a[l]);
		}
		cout<<ma;
		return 0;
	}
	else if(m==5){
		int ma=INT_MIN;
		for(int i = 1; i < n-3; i++)
			for(int j = i+1; j < n-2; j++)
				for(int k = j+1; k < n-1; k++)
					for(int l = k+1; l < n; l++)
						for(int p = l+1; p <= n; p++)ma=max(ma, a[i]&a[j]&a[k]&a[l]&a[p]);
		cout<<ma;
		return 0;
	}
	else if(m==6){
		int ma=INT_MIN;
		for(int i = 1; i < n-4; i++)
			for(int j = i+1; j < n-3; j++)
				for(int k = j+1; k < n-2; k++)
					for(int l = k+1; l < n-1; l++)
						for(int p = l+1; p < n; p++)
							for(int u = p+1; u <= n; u++)ma=max(ma, a[i]&a[j]&a[k]&a[l]&a[p]&a[u]);
		cout<<ma;
		return 0;
	}
	else if(m==7){
		int ma=INT_MIN;
		for(int i = 1; i < n-5; i++)
			for(int j = i+1; j < n-4; j++)
				for(int k = j+1; k < n-3; k++)
					for(int l = k+1; l < n-2; l++)
						for(int p = l+1; p < n-1; p++)
							for(int u = p+1; u < n; u++)
								for(int f = u+1; f <= n; f++)ma=max(ma, a[i]&a[j]&a[k]&a[l]&a[p]&a[u]&a[f]);
		cout<<ma;
		return 0;
	}
	else if(m==8){
		int ma=INT_MIN;
		for(int i = 1; i < n-6; i++)
			for(int j = i+1; j < n-5; j++)
				for(int k = j+1; k < n-4; k++)
					for(int l = k+1; l < n-3; l++)
						for(int p = l+1; p < n-2; p++)
							for(int u = p+1; u < n-1; u++)
								for(int f = u+1; f < n; f++)
									for(int r = f+1; r <= n; r++)ma=max(ma, a[i]&a[j]&a[k]&a[l]&a[p]&a[u]&a[f]&a[r]);
		cout<<ma;
		return 0;
	}
	else if(m==9){
		int ma=INT_MIN;
		for(int i = 1; i < n-7; i++)
			for(int j = i+1; j < n-6; j++)
				for(int k = j+1; k < n-5; k++)
					for(int l = k+1; l < n-4; l++)
						for(int p = l+1; p < n-3; p++)
							for(int u = p+1; u < n-2; u++)
								for(int f = u+1; f < n-1; f++)
									for(int r = f+1; r < n; r++)
										for(int yyy= r+1; yyy <= n; yyy++)ma=max(ma, a[i]&a[j]&a[k]&a[l]&a[p]&a[u]&a[f]&a[r]&a[yyy]);
		cout<<ma;
		return 0;
	}
	else if(m==n){
		int ma=a[1];
		for(int i = 2; i <= n; i++)ma&=a[i];
		cout<<ma;
		return 0;
	}
	return 0;
}
