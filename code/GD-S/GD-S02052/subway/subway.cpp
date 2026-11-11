#include<bits/stdc++.h>
using namespace std;
int w[100001],rote[100001],time[100001],k[501],line_a[10],line_b[10],a[501];
int n;
int check(int num){
	for(int i=0;i<k[n];i++){
		if(num<k[n])return n-1;
	}
	return n;
}
int connect(int la,int lb){
	for(int i=rote[k[la]];i<rote[k[la+1]-1];i++){
		for(int j=rote[k[lb]];j<rote[k[lb+1]-1];j++){
			if(i==j){
				return 
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	int c,m,d,q;
	cin >> c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin >>w[i];
	}
	for(int i=1;i<=n;i++){
		cin >>a[i];
		k[i]=k[i-1]+a[i];
		for(int j=k[i-1];j<k[i];j++){
			cin >> rote[j] >> time[j];
		}
	}
	int l_a=0,l_b=0;
	for(int i=0;i<q;i++){
		int q_a,q_b;
		cin >> q_a>> q_b;
		for(int j=0;j<k[n];j++){
			if(rote[j]==q_a){
				line_a[l_a]=check(j);
				l_a++;
			}
			if(rote[j]==q_b){
				line_b[l_b]=check(j);
				l_b++;
			}
		}
		int minn=1000000;
		for(int j=0;j<l_a;j++){
			for(int z=0;z<l_b;z++){
				minn=min(minn,connect(line_a[j],line_b[z]));
			}
		}
	}
	return 0;
}
