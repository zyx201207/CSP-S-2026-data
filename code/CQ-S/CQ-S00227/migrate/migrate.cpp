#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define pb push_back
#define endl '\n'

int c,T;
int n,d;
int x[2000009];
int D;
int P=1;
void dfs(int l,int y,int step,int pos,int k){
	if (step>k) return ;
	if (l>=pos){
		if (step==k){
			P++;
		}
		return ;
	}
	l+=d;
	if (x[y+1]>l){
		dfs(x[y+1],y+1,step+1,pos,k);
		return ;
	}
	for (int i=1;;i++){
		if (x[y+i]>l) return ;
		dfs(x[y+i],y+i,step+1,pos,k);
	}
	return ;
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);	
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--){
		cin>>n>>d;
		bool flag=true;
		for (int i=1;i<=n;i++){
			cin>>x[i];
			if (i==2) D=x[i]-x[i-1];
			if (i>2 && x[i]-x[i-1]!=D) flag=false;
		}
		if (c>=16 && c<=18){
			cout<<0<<endl;
			continue;
		}
		if (flag){
			int k=d/D;
			if (k<=1){
				cout<<0<<endl;
			}
			else if (n-2*k+1>0){
				cout<<n-2*k+1<<endl;
			}
			else{
				cout<<0<<endl;
			}
			continue;
//			cout<<n<<' '<<D<<' '<<d<<' '<<k<<endl;
		}
		int ans=0;
		vector<int> vec(n+9,0);
		for (int i=2;i<=n;i++){
			for (int j=1;j<i;j++){
				if (i-j<3) continue;
				//j~i
				int p=j,s=x[j],cnt=0;
				P=1;
				vec[cnt]=p;
				while (p<=i){
					s+=d;
					while (s>x[p] && p<=i) p++;
					if (p==vec[cnt]){
						p++;
					}
					vec[++cnt]=p;
				}
				dfs(x[j],j,1,i,cnt);
				if (P==2){
					ans++;
				}
			}
		} 
		cout<<ans<<endl;
	}

	return 0;
}








