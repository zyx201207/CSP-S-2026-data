#include<bits/stdc++.h>
using namespace std;
///不行了没时间了 这个w怎么这么难整 
long long s[500010],f[500010],w[500010],zong[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		//if(w[s[i]]==0)w[s[i]]=i;//第一次出现 
	}
	for(int i=1;i<=n;i++){
	    for(int j=0;j<=n;j++){
	    	f[j]=0;
		}
		for(int j=0;j<=m;j++){
	    	w[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(w[s[j]]==0)w[s[j]]=j;
			//w[j]--j-1 +1
			f[w[s[j]]]++;
			f[j]--;
			//w[s[j]]=0;
		}
		for(int j=i;j<=n;j++){
	    	f[j]+=f[j-1];
	    	if(f[j]==0)zong[s[j]]++;
	    }
//	    for(int j=0;j<=n;j++){
//	    	f[j]=0;
//		}
//		for(int j=0;j<=m;j++){
//	    	w[j]=0;
//		}
//        cout<<i<<"-"<<endl;
//        cout<<"f"<<' ';
//        for(int j=1;j<=n;j++){
//	    	cout<<f[j]<<" ";
//		}
//		cout<<endl;
//		cout<<"w"<<" ";
//		for(int j=1;j<=m;j++){
//	    	cout<<w[j]<<" ";
//		}  
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<zong[i]<<" ";
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		//cout<<s[f[i]]<<' ';
//		cout<<f[i]<<' ';
//	}
	return 0;
} 
//4 3
//1 2 1 3

//10 3
//3 1 2 1 3 2 3 1 2 1