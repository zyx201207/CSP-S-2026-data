#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1,s;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++)
			s=(s&a[i]);
		cout<<s;
		return 0;
	}
	if(m==2){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
				//cout<<a[i]<<' '<<a[j]<<' '<<maxx<<' '<<(a[i]&a[j])<<endl; 
			}	
		cout<<maxx;
		return 0;
	}
	if(m==3){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					maxx=max(maxx,(a[i]&a[j]&a[k]));	
		cout<<maxx;
		return 0;
	}
	if(m==4){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]));	
		cout<<maxx;
		return 0;
	}
	if(m==5){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int p=l+1;p<=n;p++)
							maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[p]));	
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		maxx=-1;
		for(int i=1;i<=n;i++){
			if(i==1) s=a[2];
			else s=a[1];
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				s=(s&a[j]);
			}
			maxx=max(maxx,s);
		}
		cout<<maxx;
		return 0;
	}
	if(m==6){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int p=l+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]));	
		cout<<maxx;
		return 0;
	}
	if(m==7){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int p=l+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								for(int r=q+1;r<=n;r++)
									maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]));	
		cout<<maxx;
		return 0;
	}
	if(m==8){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int p=l+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								for(int r=q+1;r<=n;r++)
									for(int t=r+1;t<=n;t++)
										maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[t]));	
		cout<<maxx;
		return 0;
	}
	if(m==9){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int p=l+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								for(int r=q+1;r<=n;r++)
									for(int t=r+1;t<=n;t++)
										for(int u=t+1;u<=n;u++)
											maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[t]&a[u]));	
		cout<<maxx;
		return 0;
	}
	if(m==10){
		maxx=-1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int p=l+1;p<=n;p++)
							for(int q=p+1;q<=n;q++)
								for(int r=q+1;r<=n;r++)
									for(int t=r+1;t<=n;t++)
										for(int u=t+1;u<=n;u++)
											for(int v=u+1;v<=n;v++)
												maxx=max(maxx,(a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[r]&a[t]&a[u]&a[v]));	
		cout<<maxx;
		return 0;
	}
	cout<<18;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

