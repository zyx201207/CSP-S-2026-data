/*#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[500005],b[500005][2],c[300005];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		b[a[i]][0]++;
		b[a[i]][1]=max(b[a[i]][1],i);
		c[a[i]]+=i;
		cout<<a[i]<<" : "<<c[a[i]]<<" : "<<b[a[i]][0]<<endl;
		if(b[a[i]][0]>=2){
			c[a[i]]-=i;
			cout<<endl<<endl;
			for(int j=i;j<b[a[i]][1];j++){
				c[a[j]]-=(j-i);
				cout<<a[j]<<" : "<<c[a[j]]<<endl;
			}
			break;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[500005],b[500005],c[300005],d[300005];
int main(){
	//*
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//*/
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			x++;
			b[x]=a[j];
			c[a[j]]++;
			if(c[a[j]]>=2){
				c[a[j]]=1;
				x=1;
				b[1]=a[j];
				memset(c,0,sizeof(c));
				c[a[j]]++;
			}
		}
		
		for(int j=1;j<=x;j++){
			d[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	//*
	fclose(stdin);
	fclose(stdout);
	//*/
	return 0;
}

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

