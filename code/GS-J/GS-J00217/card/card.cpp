#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=0;
	cin>>n>>m;
	
	vector<int>a(n);
	vector<int>ar(n);
	vector<int>used(m,-1);
	vector<int>desk(m,-1);
	vector<int>ans(m,0);
	
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	
	for(int game=0;game<n;game++){
		l=0;
		for(int i=0;i<n;i++){
			a[i]=ar[i];
		}
		for(int i=0;i<m;i++){
			desk[i]=-1;
			used[i]=-1;
		}
		
		for(int i=0+game;i<m;i++){
			for(int j=0;j<m;j++){
				if(a[i]!=used[j]){
					used[j]=a[i];
					used[i]=a[i];
					desk[l]=a[i];
					l+=1;
				}
				else{
					for(int h=j;h<l;h++){
						used[h]=-1;
						desk[h]=0;
						l-=1;
						//cout<<l<<endl;
					}
					desk[l]=a[i];
					
				}
			}
		}
		for(int j=0;j<l;j++){
			for(int h=0;h<m;h++){
				if(desk[j]==a[h]){
					ans[h]+=1;
				}
				
			}
			//cout<<desk[j];
		}
		//cout<<endl;
	}
	/*for(int i=0;i<m;i++){
		cout<<"No"<<' ';
	}*/
	cout<<"No";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
