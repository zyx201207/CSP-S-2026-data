#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll len=0;

struct zf{
	ll l,r;
	char c;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	
	vector<zf> zzz;
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		int a;
		char x;
		cin>>a>>x;
		zzz.push_back({len,len+a-1,x});
		len+=(long long)a;
	}
	
	ll cha=0;
	for(int i=0;i<len/2;i++){
		char x,y;
		for(int j=0;j<zzz.size();j++){
			if(zzz[j].l<=i&&zzz[j].r>=i){
				x=zzz[j].c;
				break;
			}
		}
		for(int j=0;j<zzz.size();j++){
			if(zzz[j].l<=len-i-1&&zzz[j].r>=len-i-1){
				y=zzz[j].c;
				break;
			}
		}
		if(x!=y){
			cha++;
		}
	}
	cout<<cha;
	
	return 0;
}
