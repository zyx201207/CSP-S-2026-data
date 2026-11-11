#include<bits/stdc++.h>
using namespace std;
int a[200005],t[50],ans[50];
vector<int> q[55];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i,n,j,m,h,cnt=0,l;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		j=0,h=a[i];
		while(h){
			if((h&1)==1){
		//		cout<<h<<" "<<j<<endl;
				t[j]++;
				q[j].push_back(i);
			}
			j++;
			h=(h>>1);
		}
	}
//	for(j=0;j<=5;j++){
//		cout<<t[j]<<" ";
//	}
	vector<int> p[50],s;
	int f=0;
	for(i=32;i>=0;i--){
		if(t[i]>=m){
			if(f==0){
				for(j=0;j<q[i].size();j++){
	//				cout<<q[i][j]<<" ";
					p[f].push_back(q[i][j]);
	//				cout<<p[f][j];
				}
				cnt+=(1<<i);
				f++;
			}else{
				for(j=0;j<q[i].size();j++){
	//				cout<<q[i][j]<<" ";
					for(l=0;l<p[f-1].size();l++){
						if(q[i][j]==p[f-1][l]){
	//						cout<<q[i][j]<<" ";
							s.push_back(q[i][j]);
						}
					}
				}
				if(s.size()>=m){
					cnt+=(1<<i);
					for(j=0;j<s.size();j++){
						p[f].push_back(s[j]);
					}
					f++;
				}
				s={};
			}
	//		cout<<endl;
		}
	}
	cout<<cnt;
	return 0;
}