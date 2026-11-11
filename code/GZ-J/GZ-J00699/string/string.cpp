//GZ-J00699   Ëï³çÏö 
#include <bits/stdc++.h>
using namespace std;
struct zhif{
	long long len1;
	char m;
}arr[200004];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	long long len=0,sum=0,k=0,sumzh=0,u=1;
	bool oushu=true;
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>arr[j].len1>>arr[j].m;
		len+=arr[j].len1;
	}
	if(len%2!=0){
		oushu=false;
	}
	len/=2;		
	
	while(k<(n-u))
	{
		long long i=1;
		//cout<<i<<" "<<k<<" "<<u<<" "<<arr[k].len1<<" "<<arr[k].m<<" "<<arr[n-u].len1<<" "<<arr[n-u].m<<endl;

		if(arr[k].len1>=arr[n-u].len1){
			i=arr[k].len1;
			for(;i>=0;){
				i-=arr[n-u].len1;
				if(arr[k].m!=arr[n-u].m&&i>=0){
					sumzh+=arr[n-u].len1;
					arr[k].len1-=arr[n-u].len1;
					u++;
				}
				else if(arr[k].m!=arr[n-u].m&&i<0){
					sumzh+=arr[k].len1;
					arr[n-u].len1-=arr[k].len1;
					k++;
					break;
				}
				else if(arr[k].m==arr[n-u].m&&i>=0){
					arr[k].len1-=arr[n-u].len1;
					u++;
				}
				else if(arr[k].m==arr[n-u].m&&i<0){
					arr[n-u].len1-=arr[k].len1;
					k++;
					break;
				}
			}
		}
		else{
			i=arr[n-u].len1;
			for(;i>=0;){
				i-=arr[k].len1;
				if(arr[k].m!=arr[n-u].m&&i>=0){
					sumzh+=arr[k].len1;
					arr[n-u].len1-=arr[k].len1;
					k++;
				}
				else if(arr[k].m!=arr[n-u].m&&i<0){
					sumzh+=arr[n-u].len1;
					arr[n-u].len1-=arr[k].len1;
					u++;
					break;
				}
				else if(arr[k].m==arr[n-u].m&&i>=0){
					arr[n-u].len1-=arr[k].len1;
					k++;
				}
				else if(arr[k].m==arr[n-u].m&&i<0){
					arr[k].len1-=arr[n-u].len1;
					u++;
					break;
				}
			}
		}
			//cout<<i<<" "<<k<<" "<<u<<" "<<arr[k].len1<<" "<<arr[k].m<<" "<<arr[n-u].len1<<" "<<arr[n-u].m<<endl<<endl;
	}
	cout<<sumzh;
	fclose(stdin);
	fclose(stdout);
}

