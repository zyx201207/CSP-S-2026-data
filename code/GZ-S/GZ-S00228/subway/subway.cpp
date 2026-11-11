//GZ-S00228 遵义市第十九中学 张锣址杨 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k_t[100005],xs[100005],xz[1005][1005],t_tai[1005][1005];
int start[100005],end[100005],num[100005]={0};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i = 0;i<m;i++){
		cin >>k_t[i];
	}
	for(int i = 0;i < n;i++){
		cin>>xs[i];
		for(int j = 0;j < xs[i];j++){
			cin >> xz[i][j]>>t_tai[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>start[i]>>end[i];
	}
	for(int i = 0;i < q;i++){
		int q=-1,z=-1;
	for(int j = 0;j <n;j++){
		for(int k = 0;k < xs[j];k++){
			if(xz[j][k]==start[i]&&q==-1){
				num[i]+=k_t[start[i]-1];
				num[i]+=t_tai[j][k];
				q=j;
			}
			if(xz[j][k]==end[i]&&z==-1){
				num[i]+=t_tai[j][k];
				num[i]+=k_t[end[i]-1];
				z=j;
			}
		}
		if(q==z&&q!=-1){
			break;
		}
	}
cout<<num[i] << endl;
}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

