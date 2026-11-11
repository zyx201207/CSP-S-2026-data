#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int mem[maxn],j[maxn];
int len[maxn][40],shu[40],max_x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>mem[i];
		for(j[i]=0;mem[i]!=0;j[i]++){
			len[i][j[i]]=mem[i]%2;
			mem[i]/=2;
		}
	}
	for(int i=0;i<n;i++){
		for(int q=i;q<n;q++){
			int w=0;
			for(int q1=0;q1<=max(j[i],j[q]);q1++){
				shu[q1]=len[i][q1]&len[q][q1];
				int sum=1;
				for(int s=0;s<q1;s++){
					if(shu[q1]==0){
						sum=0;
						break;
					}
					sum*=2;
				}
				if(q1==1&&shu[q1==0])
					continue;
				if(sum!=1)
					w+=sum;
			}
			max_x=max(max_x,w);
		}
	}
	cout<<max_x;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
