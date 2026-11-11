#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int ans=0,m;
bool tf(){
	int c[200000]={0};
	for(int i=0;i<m;i++){
		if(b[i]>=0){
			if(!c[b[i]]){
				c[b[i]]=1;
			}
			else return false;
		}
		else return false;
	}
	return true;
}
void an(){
	int gh=a[b[0]];
	for(int i=1;i<m;i++){
		gh=gh and a[b[i]];
	}
	ans=max(ans,gh);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		b.push_back(i);
	}
	for(int i=m-1;i>=0;i){
		if(b[i]+1<n){
			b[i]++;
			for(int j=1;i+j<m;j++){
				if(b[i]-j>0) b[i+j]=b[i]-j;
				else b[i+j]=0;
			}
			i=m-1;
			if(tf()) an();
		}
		else{
			i--;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
