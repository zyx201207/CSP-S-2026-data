#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a;
int aa;
int maxp;
int res,cnt;
int len;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&aa);
		a.push_back(aa);
		maxp=max(maxp,int(log2(aa)));
	}
	for(int i=maxp;i>=0;i--){
		len=a.size();
		cnt=0;
		for(int j=0;j<len;j++){
			if(((a[j]>>i)&1)==1) cnt++; 
		}
		if(cnt>=m){
			//cout<<cnt<<endl;
			res+=pow(2,i);
			for(int j=0;j<len;j++){
				if(((a[j]>>i)&1)==0) a.erase(a.begin()+j);
			}
		}
	}
	printf("%d",res);
	return 0;
} 
