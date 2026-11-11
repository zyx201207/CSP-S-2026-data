#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
long long t[N+5][30],a1[N+5],a2[N+5];
int tj[31]={1};
void einit(){
	for(int i=1;i<=30;i++){
		tj[i]=tj[i-1]*2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	einit();
	int n,m;
	cin>>n>>m;
	long long a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int max_tj=0;
	for(int i=1;i<=n;i++){
		int idx=30;
		while(a[i]>0){
			if(a[i]>=tj[idx]){
				max_tj=max(max_tj,idx);
				a[i]-=tj[idx];
				t[i][idx]=1;
			}
			idx--;
		}
	}
	int tn=n;
	max_tj++;
	bool flag=false;
	for(int i=max_tj;i>=0;i--){
		long long tmp_idx=1,tmp_cnt=0;
		for(int j=1;j<=tn;j++){
			if(t[j][i]==1){
				a2[tmp_idx++]=b[j];
				tmp_cnt++;
			}
		}
		if(tmp_cnt==m){
			long long num=a2[1];
			for(int j=2;j<=tmp_cnt;j++){
				num&=a2[j];
			}
			cout<<num;
			return 0;
		}else if(tmp_cnt>m){
			tn=tmp_cnt;
			for(int j=1;j<=tmp_cnt;j++){
				b[j]=a2[j];
			}
			flag=true;
		}
	}
	if(flag){
		int num2=b[1];
		for(int i=2;i<=m;i++){
			num2&=b[i];
		}
		cout<<num2;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
