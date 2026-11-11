//GZ-S00099 王满霖 贵州省实验中学 
#include<bits/stdc++.h>
using namespace std;
long long sb[500010];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout)；
	long long N,M;cin>>N>>M;
	int s=1;
	for(int i=0;i<N;i++){
		cin>>sb[i];
	}
	sort(sb,sb+N,cmp);
	int con=0;
	for(int i=1;i<N;i++){
		if(con!=0){
			con--;
			continue;
		}
		long long dsb=sb[i];
		int j=i-1;
		int m=M;
		int sbs=1;
		while(j>=0&&m>=sb[i]-sb[j]){
			m-=(sb[i]-sb[j]);
			sbs++;
			j--;
		}
		int k=i+1;
		while(sb[k]==sb[i]&&k<N){
			con++;
			sbs++;
			k++;
		}
		s=max(s,sbs);
	}
	cout<<s;
	return 0;
} 
