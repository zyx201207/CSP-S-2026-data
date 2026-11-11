#include<bits/stdc++.h>
using namespace std;
long long nn,mm,aa[10000000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>nn>>mm;
	for(int i=1;i<=nn;i++){
		cin>>aa[i];
	}
	sort(aa+1,aa+1+nn);
	if(mm==1){
		cout<<aa[nn];
	}
	else if(mm==2){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				ans=max(ans,aa[a]&aa[b]);
		cout<<ans;
	}
	else if(mm==3){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					ans=max(ans,aa[a]&aa[b]&aa[c]);
		cout<<ans;
	}
	else if(mm==4){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]);
		cout<<ans;
	}
	else if(mm==5){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]);
		cout<<ans;
	}
	else if(mm==6){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]);
		cout<<ans;
	}
	else if(mm==7){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]);
		cout<<ans;
	}
	else if(mm==8){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]);
		cout<<ans;
	}
	else if(mm==9){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]);
		cout<<ans;
	}
	else if(mm==10){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]);
		cout<<ans;
	}
	else if(mm==11){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]);
		cout<<ans;
	}
	else if(mm==12){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]);
		cout<<ans;
	}
	else if(mm==13){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]);
		cout<<ans;
	}
	else if(mm==14){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															for(int n=1;n<=nn;n++)
																ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]&aa[n]);
		cout<<ans;
	}
	else if(mm==15){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															for(int n=1;n<=nn;n++)
																for(int o=1;o<=nn;o++)
																	ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]&aa[n]&aa[o]);
		cout<<ans;
	}
	else if(mm==16){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															for(int n=1;n<=nn;n++)
																for(int o=1;o<=nn;o++)
																	for(int p=1;p<=nn;p++)
																		ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]&aa[n]&aa[o]&aa[p]);
		cout<<ans;
	}
	else if(mm==17){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															for(int n=1;n<=nn;n++)
																for(int o=1;o<=nn;o++)
																	for(int p=1;p<=nn;p++)
																		for(int q=1;q<=nn;q++)
																			ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]&aa[n]&aa[o]&aa[p]&aa[q]);
		cout<<ans;
	}
	else if(mm==18){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															for(int n=1;n<=nn;n++)
																for(int o=1;o<=nn;o++)
																	for(int p=1;p<=nn;p++)
																		for(int q=1;q<=nn;q++)
																			for(int r=1;r<=nn;r++)
																				ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]&aa[n]&aa[o]&aa[p]&aa[q]&aa[r]);
		cout<<ans;
	}
	else if(mm==19){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															for(int n=1;n<=nn;n++)
																for(int o=1;o<=nn;o++)
																	for(int p=1;p<=nn;p++)
																		for(int q=1;q<=nn;q++)
																			for(int r=1;r<=nn;r++)
																				for(int s=1;s<=nn;s++)
																					ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]&aa[n]&aa[o]&aa[p]&aa[q]&aa[r]&aa[s]);
		cout<<ans;
	}
	else if(mm==19){
		for(int a=1;a<=nn;a++)
			for(int b=1;b<=nn;b++)
				for(int c=1;c<=nn;c++)
					for(int d=1;d<=nn;d++)
						for(int e=1;e<=nn;e++)
							for(int f=1;f<=nn;f++)
								for(int g=1;g<=nn;g++)
									for(int h=1;h<=nn;h++)
										for(int i=1;i<=nn;i++)
											for(int j=1;j<=nn;j++)
												for(int k=1;k<=nn;k++)
													for(int l=1;l<=nn;l++)
														for(int m=1;m<=nn;m++)
															for(int n=1;n<=nn;n++)
																for(int o=1;o<=nn;o++)
																	for(int p=1;p<=nn;p++)
																		for(int q=1;q<=nn;q++)
																			for(int r=1;r<=nn;r++)
																				for(int s=1;s<=nn;s++)
																					for(int t=1;t<=nn;t++)
																						ans=max(ans,aa[a]&aa[b]&aa[c]&aa[d]&aa[e]&aa[f]&aa[g]&aa[h]&aa[i]&aa[j]&aa[k]&aa[l]&aa[m]&aa[n]&aa[o]&aa[p]&aa[q]&aa[r]&aa[s]&aa[t]);
		cout<<ans;
	}
	return 0;
}
