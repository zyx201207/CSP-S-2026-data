#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005];
int main(){
	ifstream fin("crystal.in");//
	ofstream fout("crystal.out");
	int n;long long m;
	fin>>n>>m;
	for(int i=1;i<=n;i++){
		fin>>a[i];
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++) cout<<a[i]<<endl;//
	int x=1,y=0;
	while(x<n){
		if(a[x]==a[x+1]){
			y++;c[y]=a[x];
			while(a[x]==a[x+1]&&x<n){
				b[y]++;
				x++;
			}
			x++;
			b[y]++;
		}
		else{
			y++;
			c[y]=a[x];
			b[y]=1;
			x++;
		}
	}
	if(a[n]==a[n-1]) b[y]++;
	else{
		y++;
		c[y]=a[n];
		b[y]=1;
	}
	long long ans=b[1];
	for(int i=2;i<=y;i++){
		long long mm=m,anss=b[i];
		for(int j=i-1;j>0;j--){
			int k=b[j];
			while(mm-(c[i]-c[j])>=0&&k>0){
				mm=mm-(c[i]-c[j]);
				anss++;
				k--;
			}
			if(k>0) break;
		}
		ans=max(ans,anss);
	}
	fout<<ans;
	fin.close();
	fout.close();
}
