#include<bits/stdc++.h>
using namespace std;
int n,m,arr[100050],x=0,ans=1,z;
int mid,l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	if(n>16){
		if(n>5000){
			bool d=true;
			cin>>arr[0];
			cin>>arr[1];
			cin>>arr[2];
			for(int i=3;i<n;i++){
				cin>>arr[i];
				if(arr[i]-arr[i-1]!=arr[i-1]-arr[i-2]){
					d=false;
					z=i;
					break;
				}
			}
			if(d){
				mid=n/2+1;
				l=mid-1;
				r=mid+1;
				int mt=m;
					while(x<=mt){
					//cout<<"a";
					if(l>0&&arr[l]+x==arr[mid]){
						ans++;
						mt-=x;
						l--;
					}
					else if(r<=n&&arr[r]+x==arr[mid]){
						ans++;
						mt-=x;
						r++;
					}
					else x++;
				}
				cout<<ans;
				return 0;
			}
			else{
				for(int i=z+1;i<n;i++) cin>>arr[i];
				for(int i=0;i<n;i++){
					for(int j=0;j<n-i;j++){
						if(arr[j]>arr[j+1]){
							int x=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=x;
						}
					}
			}
				mid=n/2+1;
				l=mid-1;
				r=mid+1;
				int mt=m;
				while(x<=mt){
					//cout<<"a";
					if(l>0&&arr[l]+x==arr[mid]){
						ans++;
						mt-=x;
						l--;
					}
					else if(r<=n&&arr[r]+x==arr[mid]){
						ans++;
						mt-=x;
						r++;
					}
					else x++;
				}
				cout<<ans;
				return 0;
			}
			 	
		}
		else{
		
			for(int i=0;i<n;i++) cin>>arr[i];
			for(int i=0;i<n;i++){
					for(int j=0;j<n-i;j++){
						if(arr[j]>arr[j+1]){
							int x=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=x;
						}
					}
			}
			mid=n/2+1;
			l=mid-1;
			r=mid+1;
			int mt=m;
			while(x<=mt){
				//cout<<"a";
				if(l>0&&arr[l]+x==arr[mid]){
					ans++;
					mt-=x;
					l--;
				}
				else if(r<=n&&arr[r]+x==arr[mid]){
					ans++;
					mt-=x;
					r++;
				}
				else x++;
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(arr[j]>arr[j+1]){
				int x=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=x;
			}
		}
	}
	int anss=0;
	//for(int mid=2;mid<n-1;mid++){
		mid=n/2+1;
		l=mid-1;
		r=mid+1;
		int mt=m;
		while(x<=mt){
			//cout<<"a";
			if(l>0&&arr[l]+x==arr[mid]){
				ans++;
				mt-=x;
				l--;
			}	
			else if(r<=n&&arr[r]+x==arr[mid]){
				ans++;
				mt-=x;
				r++;
			}
			else x++;
		}
		//if(ans>anss) anss=ans;

	
	cout<<ans;
	//cout<<arr[mid];
	return 0;
	
	
}
