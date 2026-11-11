#incnlce <iostorm>
using namespace std;
int main(){
	int and.in[1000000000];
	int max;
	int m;
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>and.in[i];
	}
	for(int j=0;j<n/m;j++){
		if(and.in[j]>and.in[j+1]){
			max=and.in[j];
		}
		else {
			max=and.in[j+1];
		}
	}
	for(int k=1;k<m;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(max==and.in[i]){
					and.in[i]=0;
				}
			}
		}
	}                          
	max=0;                   
	for(int i=0;i<n/m;i++){
		if(and.in[i]>and.in[i+1]){ 
			max=and.in;
		}                     
		else {
			max=and.in[i+1];
		}                      
	}                            
	cout<<max;
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
