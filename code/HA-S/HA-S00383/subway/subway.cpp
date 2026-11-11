#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int w[N],k[N],a[20][N],t[20][N];
int ques[N],quee[N];
void solve(){
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	if(n==1){
		for(int i=0;i<n;i++){
			cin>>k[i];
			for(int j=0;j<k[i];j++){
				cin>>a[k[i]][j]>>t[k[i]][j];
			}
		}
		for(int i=0;i<q;i++){
			cin>>ques[i]>>quee[i];
			cout<<w[ques[i]]+w[quee[i]]+t[k[0]][ques[i]]+t[k[0]][quee[i]]<<endl;
		}
	}
	else if(n==2){
		int k1,k2,a1[N],a2[N],t1[N],t2[N];
		cin>>k1;
		for(int i=0;i<k1;i++)cin>>a1[i]>>t1[i];
		cin>>k2;
		for(int i=0;i<k2;i++)cin>>a2[i]>>t2[i];
		for(int i=0;i<q;i++){
			cin>>ques[i]>>quee[i];
			int sum=0;
			for(int j=0;j<k1;j++){
				if(ques[i]==a1[j])sum+=t1[j];
				if(quee[i]==a1[j])sum+=t1[j];
			}
			for(int j=0;j<k2;j++){
				if(ques[i]==a2[j])sum+=t2[j];
				if(quee[i]==a2[j])sum+=t2[j];
			}
			for(int j=0;j<k1;j++){
				bool st=0;
				for(int o=0;o<k2;o++){
					if(a1[j]==a2[o]){
					sum=sum+t1[j]+t2[o];
					st=1;break;
					}
				}
				if(st)break;
			}
			sum=sum+w[ques[i]-1]+w[quee[i]-1];
			cout<<sum<<endl;
		}
	}
} 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
