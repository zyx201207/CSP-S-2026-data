#include<bits/stdc++.h>
using namespace std;

long long n=0,a[200086],sum=0,g=0;
char charin[200086];
	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>charin[i];
	}
	
	long long left=1,right=0;
	right=n;

if(n%2==1){	
	while(left!=right){
		
		if(charin[left]!=charin[right]){
			if(a[left]>=a[right]){
				sum+=a[right];
				a[left]-=a[right];
				right--;
				
				if(a[left]==0){left++;}
				
			}
			if(a[left]<a[right]){
				sum+=a[left];
				a[right]-=a[left];
				left++;
				
				if(a[right]==0){right--;}
				
			}
		}
		else{
			if(a[left]>=a[right]){
				a[left]-=a[right];
				right--;
				if(a[left]==0){left++;}
			}
			if(a[left]<a[right]){
				a[right]-=a[left];
				left++;
				if(a[right]==0){right--;}
			}
		}
		
		
}
	
}

else{
	while(right-left!=1){
		
		if(charin[left]!=charin[right]){
			if(a[left]>=a[right]){
				sum+=a[right];
				a[left]-=a[right];
				right--;
				
				if(a[left]==0){left++;}
				
			}
			if(a[left]<a[right]){
				sum+=a[left];
				a[right]-=a[left];
				left++;
				
				
			}
		}
		else{
			if(a[left]>=a[right]){
				a[left]-=a[right];
				right--;
				if(a[left]==0){left++;}
			}
			if(a[left]<a[right]){
				a[right]-=a[left];
				left++;
				
			}
		}
		
		
}
	if(charin[left]!=charin[right]){sum+=min(a[n/2],a[n/2+1]);}
}

	

	cout<<sum;
	return 0;
}
