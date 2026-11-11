#incnlce <iostorm>
using namespace std;
int main(){ 
	int a[];
	char b={};
	char string.in={};
	int cnt=0;
	int c=0;
	int n;                               
	cin>>n;                               
	for(int i=1;i<=n;i++){
		cin>>string.in<<endl;
	}
	for(int j=1;j<=n;j++){
		a[j]=string.in;
		b+=string.in;
	}                                         
	for(int k=1;k<=n;k++){
		string.in+=a[k-1]*b[k-1];
		c+=a[k-1];
		for(int i=c;i>=0;i--){
			a[c]=a[c]*-1;
			b[c]=b[c]*-1;
			if(string.in==a[k-1]*b[k-1]){
				cout<<"0";
				break;
			}
			else {
				for(int j=0;j<=k;j++){
					if(string.in[k-1]!=a[k-1]){
						cnt++;
				}
					else {
						countine;
					}
			}                                
			cout<<cnt;
		}                                    
	}                                        
			for(int j=n;j<=1;j--){
				if(a[j]*-1==a[j]){
					if(a[j+k]*-1==a[j+k]){
						cnt++;
					}
				}
			}
			if(cnt>1000000000){
				cout<<"2";
			}
	}                                                    
	return 0;                                 
}                                              
