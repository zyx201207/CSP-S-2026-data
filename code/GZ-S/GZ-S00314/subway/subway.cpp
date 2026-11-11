//GZ-S00314 贵阳市第三实验中学 王钦澄 
#include<bits/stdc++.h>
using namespace std;
vector<long long> w,k;
struct str{
	int a,t;
}p[500000][500000];
int main(){
	//	[Error] no match for 'operator[]' (operand types are 'std::pair<int, int>' and 'int')
	//[Error] missing template arguments before '(' token
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	w=vector<long long> (m+5);
	k=vector<long long> (n+5);
//	a=vector<vector<int,int> > (n+5);
//	t=vector<vector<int,int> > (n+5);
	for(int i=0;i<m;i++) cin >> w[i];
	for(int i=0;i<n;i++){
		cin >> k[i];
		for(int j=0;j<k[i];j++){
			cin >> c;
		}
	}
	while(q--){
		int x,y;
		cin >> x >> y;
	}
}


