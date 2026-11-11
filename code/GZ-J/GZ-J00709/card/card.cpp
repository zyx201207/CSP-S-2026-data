// GZ-J00709 遵义市第十六中学 袁昊辰
#include <fstream>
#include <vector>

#define filename "card1"

unsigned m, n;
std::vector<unsigned> a, l, cards;

int main()
{
	std::ifstream inFile;
	std::ofstream outFile;
	inFile.open(filename ".in");
	outFile.open(filename ".out");

	inFile >> n >> m;
	a.resize(n);
	l.resize(m, 0);
	cards.reserve(n);
	for (unsigned i = 0; i < n; i++)
	{
		inFile >> a[i];
	}

	inFile.close();

	for (unsigned i = 0; i < n; i++)
	{
		for (unsigned j = i; j < n; j++)
		{
			for (unsigned k = 0; k < cards.size(); k++)
			{
				if (cards[k] == a[j])
				{
					cards.erase(cards.begin()+k+1,cards.end());
					goto a;
				}
			}
			cards.push_back(a[j]);
			a: NULL;
		}
		for (unsigned j = 0; j < cards.size(); j++)
		{
			l[cards[j]]++;
		}
		cards.clear();
	}
	
	for (unsigned i = 0; i < l.size(); i++)
	{
		outFile << l[i] << ' ';
	}

	outFile.close();

	return 0;
}

