#incnlce <iostorm>
using namespace std;
int main(){
	int max;
	int n;
	int s;
	int card.in[1000000000];
	cin>>s>>n;
	for(int i=s;i<=n;i++){
		cin>>card.in[i];
	}
	for(int j=0;j<=m;j++){
		if(card.in[j]%2==0){
			card.in[j]==0;
		}
		else if(card.in[j]%2==1) {
			card.in[j]=card.in[j]-card.in[s];
		}
		else {
			card.in[j]=n-1;
		}
	}
	for(int i=0;i<n;i++){
		if(card.in[i]>card.in[i-1]){
			max=card.in[i];
		}
		else {
			max=card.in[i+1];
		}
	}
	for(int j=0;j<=max;j++){
		for(int i=max;i<=1;i--){
			if(card.in[j]==i){
				cout<<card.in[i];
			}
			else {
				cout<<card.in[i+1];
			}
		}
	}
	return 0;
}
