#include <bits/stdc++.h>
using namespace std;
long long n,a[200009],idx[200009][2],ans=0,lenS=0,maxa=-1;
char c[200009];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    idx[0][1]=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		lenS+=a[i];
		if(i==1) idx[i][0]=1;
		else idx[i][0]=idx[i-1][1]+1;
		idx[i][1]=idx[i-1][1]+a[i];
		maxa=max(a[i],maxa);
//		cout << idx[i][0] << ' ' << idx[i][1]<< '\n';
	}
	long long sumn=a[1];
	for(int i=1;i<=n && sumn<=lenS/2+1;i++){
		long long st=lenS-idx[i][1]+1,ed=lenS-idx[i][0]+1;
		for(int j=n;j>i;j--){
					
			if(c[i]!=c[j]){
				//cout <<"i:" << i <<" j:" << j << '/'<<st << ' '<< ed<<'/'<<idx[j][0]<<' ' <<idx[j][1] << '|'<< c[i] << ' '<< c[j]<<":\n";
				
				ans+=max(0ll,min(ed,idx[j][1])-max(st,idx[j][0])+1);
				//cout << max(st,idx[j][0])<<' '<< min(ed,idx[j][1]) <<'|';
				//cout << max(0ll,min(ed,idx[j][1])-max(st,idx[j][0])+1) << '\n';
			}
		}
		if(i<n) sumn+=a[i+1];
		//cout << "\nsumn:" << sumn << " lenS/2:"<<lenS/2<<'\n';
	}
	cout << ans;
	return 0;
}

