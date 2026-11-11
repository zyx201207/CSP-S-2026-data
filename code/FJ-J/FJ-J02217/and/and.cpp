#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,maxx=-1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)
			maxx=max(a[i],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxx=max(a[i]&a[j],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					maxx=max(a[i]&a[j]&a[k],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==4){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						maxx=max(a[i]&a[j]&a[k]&a[b],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==5){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							maxx=max(a[i]&a[j]&a[k]&a[b]&a[c],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==6){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==7){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==8){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==9){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==10){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==11){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==12){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==13){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==14){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															for(int q=p+1;q<=n;q++)
																maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==15){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															for(int q=p+1;q<=n;q++)
																for(int r=q+1;r<=n;r++)
																	maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==16){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															for(int q=p+1;q<=n;q++)
																for(int r=q+1;r<=n;r++)
																	for(int s=r+1;s<=n;s++)
																		maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==17){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															for(int q=p+1;q<=n;q++)
																for(int r=q+1;r<=n;r++)
																	for(int s=r+1;s<=n;s++)
																		for(int t=s+1;t<=n;t++)
																			maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==18){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															for(int q=p+1;q<=n;q++)
																for(int r=q+1;r<=n;r++)
																	for(int s=r+1;s<=n;s++)
																		for(int t=s+1;t<=n;t++)
																			for(int u=t+1;u<=n;u++)
																				maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==19){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															for(int q=p+1;q<=n;q++)
																for(int r=q+1;r<=n;r++)
																	for(int s=r+1;s<=n;s++)
																		for(int t=s+1;t<=n;t++)
																			for(int u=t+1;u<=n;u++)
																				for(int v=u+1;v<=n;v++)
																					maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v],maxx);
		cout<<maxx;
		return 0;
	}
	if(m==20){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int b=k+1;b<=n;b++)
						for(int c=b+1;c<=n;c++)
							for(int d=c+1;d<=n;d++)
								for(int e=d+1;e<=n;e++)
									for(int f=e+1;f<=n;f++)
										for(int g=f+1;g<=n;g++)
											for(int h=g+1;h<=n;h++)
												for(int l=h+1;h<=n;h++)
													for(int o=l+1;o<=n;o++)
														for(int p=o+1;p<=n;p++)
															for(int q=p+1;q<=n;q++)
																for(int r=q+1;r<=n;r++)
																	for(int s=r+1;s<=n;s++)
																		for(int t=s+1;t<=n;t++)
																			for(int u=t+1;u<=n;u++)
																				for(int v=u+1;v<=n;v++)
																					for(int w=v+1;w<=n;w++)
																						maxx=max(a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w],maxx);
		cout<<maxx;
		return 0;
	}
	return 0;
}
