#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
int a[N];
int b[N],lenb;
bool v[N];
int txt[N];
int main(){
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		lenb=1;
		for(int j=i;j<=n;j++){
			
			if(v[a[j]]==1){
				int k=j-i;
				while(1==1){
					if(b[k]==a[j])break;
					v[b[k]]=0;
					b[k]=0;
					k--;
					
				}
				lenb=k+1;
				v[a[j]]=1;
//				lenb--;
			}else{
				b[lenb]=a[j];
				v[a[j]]=1;
				lenb+=1;
			}
			
			//if(b[lenb-1]==a[j])lenb--;
			
		}
		
//		for(int j=1;j<lenb;j++)cout<<b[j]<<" ";
//		cout<<endl;
		
		for(int j=1;j<lenb;j++){
			txt[b[j]]+=1;
		}
		for(int j=1;j<=n;j++){
			b[j]=0;
			v[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<txt[i]<<" ";
	}
	return 0;
}
