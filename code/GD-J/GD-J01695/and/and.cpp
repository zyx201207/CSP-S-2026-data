#include<bits/stdc++.h>
using namespace std;
struct stu{
	int num,w;
	bool total[50];
}a[200003];
bool cmp(stu a,stu b){
	if(a.w==b.w){
		int i=a.w;
		while(i>=0&&a.total[i]!=b.total[i]){
			i--;
		}
		return a.total[i];
	}
	return a.w>b.w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i].num);
		int k=a[i].num,j=0;
		while(k>0){
			if(k%2) a[i].total[j]=true;
			else a[i].total[j]=false;
			k/=2;
			j++;
		}
		a[i].w=j-1;
	}
	sort(a,a+n,cmp);
	int ans=a[0].num;
	for(int i=1;i<m;i++){
		ans&=a[i].num;
	}
	cout<<ans<<endl;
	return 0;
}
